function MoveFileToSource(rootDir)
% MoveFileToSource
% Collect Simulink-generated C/H files for the STM32 BLDC project.
%
% Project structure:
%   D:\BLDC\
%       slprj\ert\
%       BSW\bldc_stm32\Drivers\
%
% Main model generated directory:
%   D:\BLDC_MOTOR_ASW_ert_rtw
%
% Output directories:
%   D:\BLDC\Source_Simulink
%   D:\BLDC\BSW\bldc_stm32\Drivers\Source_Simulink
%
% Notes:
%   - ert_main.c is excluded because STM32 has its own main.c.
%   - Existing output directories are replaced without backup.
%   - Only .c and .h files directly inside each source directory
%     are copied.

    %% 1. Configuration

    if nargin < 1 || isempty(rootDir)
        rootDir = 'D:\BLDC';
    end

    rootDir = char(rootDir);
    projectDir = rootDir;

    % Simulink generated files: D:\slprj\ert
    slprjDir = 'D:\slprj';
    ertDir = fullfile(slprjDir, 'ert');
    
    % Shared utilities
    sharedDir = fullfile(ertDir, '_sharedutils');

    % Main model generated output is next to D:\BLDC
    mainModelName = 'BLDC_MOTOR_ASW';

    mainModelSrc = fullfile( ...
        fileparts(projectDir), ...
        [mainModelName '_ert_rtw']);

    % Project output
    dstRoot = fullfile(projectDir, 'Source_Simulink');

    % STM32 output
    stm32Dst = fullfile( ...
        projectDir, ...
        'BSW', ...
        'bldc_stm32', ...
        'Drivers', ...
        'Source_Simulink');

    % Temporary staging directory
    tempDir = fullfile(projectDir, 'Source_Simulink_tmp');


    %% 2. Validate source directories

    if ~exist(projectDir, 'dir')
        error('Project directory not found: %s', projectDir);
    end

    if ~exist(ertDir, 'dir')
        error('Simulink ERT directory not found: %s', ertDir);
    end

    if ~exist(mainModelSrc, 'dir')
        error('Main model source directory not found: %s', ...
            mainModelSrc);
    end

    if ~exist(sharedDir, 'dir')
        error('Shared utilities directory not found: %s', ...
            sharedDir);
    end

    fprintf('\n');
    fprintf('============================================\n');
    fprintf(' Collect Simulink-generated source files\n');
    fprintf('============================================\n');
    fprintf('Project directory : %s\n', projectDir);
    fprintf('Main model source : %s\n', mainModelSrc);
    fprintf('SWC source        : %s\n', ertDir);
    fprintf('Shared utilities  : %s\n\n', sharedDir);


    %% 3. Prepare temporary output directory

    if exist(tempDir, 'dir')
        [ok, msg] = rmdir(tempDir, 's');

        if ~ok
            error('Cannot remove temporary directory: %s', msg);
        end
    end

    [ok, msg] = mkdir(tempDir);

    if ~ok
        error('Cannot create temporary directory: %s', msg);
    end


    %% 4. Copy main model, excluding ert_main.c

    mainModelDst = fullfile(tempDir, mainModelName);

    [ok, msg] = mkdir(mainModelDst);

    if ~ok
        error('Cannot create main model directory: %s', msg);
    end

    mainFiles = dir(mainModelSrc);
    mainFileCount = 0;

    for i = 1:numel(mainFiles)

        if mainFiles(i).isdir
            continue;
        end

        fileName = mainFiles(i).name;
        [~, ~, ext] = fileparts(fileName);

        % Exclude Simulink-generated entry point.
        % STM32 project already has its own main.c.
        if strcmpi(fileName, 'ert_main.c')
            fprintf('[SKIP] %s\n', fileName);
            continue;
        end

        % Copy only C/H files.
        if strcmpi(ext, '.c') || strcmpi(ext, '.h')

            srcFile = fullfile(mainModelSrc, fileName);
            dstFile = fullfile(mainModelDst, fileName);

            [ok, msg] = copyfile(srcFile, dstFile, 'f');

            if ~ok
                error('Cannot copy main model file %s: %s', ...
                    srcFile, msg);
            end

            mainFileCount = mainFileCount + 1;
        end
    end

    % Check required model files.
    requiredMainFiles = {
        'BLDC_MOTOR_ASW.c'
        'BLDC_MOTOR_ASW.h'
        'BLDC_MOTOR_ASW_private.h'
        'BLDC_MOTOR_ASW_types.h'
    };

    for i = 1:numel(requiredMainFiles)

        filePath = fullfile( ...
            mainModelDst, requiredMainFiles{i});

        if ~exist(filePath, 'file')
            error('Required main model file is missing: %s', ...
                filePath);
        end
    end

    fprintf('[MAIN] %s: copied %d C/H files\n', ...
        mainModelName, mainFileCount);


    %% 5. Automatically collect SWC directories

    entries = dir(ertDir);
    swcCount = 0;
    swcFileTotal = 0;

    for i = 1:numel(entries)

        if ~entries(i).isdir
            continue;
        end

        folderName = entries(i).name;

        % Ignore special directories.
        if strcmp(folderName, '.') || ...
           strcmp(folderName, '..') || ...
           strcmp(folderName, '_sharedutils')
            continue;
        end

        swcSrc = fullfile(ertDir, folderName);
        swcFiles = dir(swcSrc);

        % Determine whether this folder contains C/H files.
        hasCode = false;

        for j = 1:numel(swcFiles)

            if swcFiles(j).isdir
                continue;
            end

            [~, ~, ext] = fileparts(swcFiles(j).name);

            if strcmpi(ext, '.c') || strcmpi(ext, '.h')
                hasCode = true;
                break;
            end
        end

        % Ignore directories without generated C/H files.
        if ~hasCode
            continue;
        end

        swcDst = fullfile(tempDir, folderName);

        [ok, msg] = mkdir(swcDst);

        if ~ok
            error('Cannot create SWC directory %s: %s', ...
                swcDst, msg);
        end

        swcFileCount = 0;

        for j = 1:numel(swcFiles)

            if swcFiles(j).isdir
                continue;
            end

            fileName = swcFiles(j).name;
            [~, ~, ext] = fileparts(fileName);

            if strcmpi(ext, '.c') || strcmpi(ext, '.h')

                srcFile = fullfile(swcSrc, fileName);
                dstFile = fullfile(swcDst, fileName);

                [ok, msg] = copyfile(srcFile, dstFile, 'f');

                if ~ok
                    error('Cannot copy SWC file %s: %s', ...
                        srcFile, msg);
                end

                swcFileCount = swcFileCount + 1;
            end
        end

        swcCount = swcCount + 1;
        swcFileTotal = swcFileTotal + swcFileCount;

        fprintf('[SWC]  %s: copied %d C/H files\n', ...
            folderName, swcFileCount);
    end

    if swcCount == 0
        warning('No SWC folders containing C/H files were found.');
    end


    %% 6. Copy shared utility C/H files into output root

    sharedFiles = dir(sharedDir);
    sharedFileCount = 0;

    for i = 1:numel(sharedFiles)

        if sharedFiles(i).isdir
            continue;
        end

        fileName = sharedFiles(i).name;
        [~, ~, ext] = fileparts(fileName);

        if strcmpi(ext, '.c') || strcmpi(ext, '.h')

            srcFile = fullfile(sharedDir, fileName);
            dstFile = fullfile(tempDir, fileName);

            [ok, msg] = copyfile(srcFile, dstFile, 'f');

            if ~ok
                error('Cannot copy shared utility %s: %s', ...
                    srcFile, msg);
            end

            sharedFileCount = sharedFileCount + 1;
        end
    end

    % Ensure rtwtypes.h exists in the collected output.
    if ~exist(fullfile(tempDir, 'rtwtypes.h'), 'file')
        error(['rtwtypes.h was not found in the output root. ', ...
            'Check the generated code directories.']);
    end

    fprintf('[SHARED] Copied %d C/H files\n', sharedFileCount);


    %% 7. Replace project Source_Simulink directory

    if exist(dstRoot, 'dir')
        [ok, msg] = rmdir(dstRoot, 's');

        if ~ok
            error('Cannot remove old Source_Simulink: %s', msg);
        end
    end

    [ok, msg] = movefile(tempDir, dstRoot);

    if ~ok
        error('Cannot move collected files to %s: %s', ...
            dstRoot, msg);
    end


    %% 8. Replace STM32 Drivers/Source_Simulink directory

    stm32Parent = fileparts(stm32Dst);

    if ~exist(stm32Parent, 'dir')
        [ok, msg] = mkdir(stm32Parent);

        if ~ok
            error('Cannot create STM32 destination parent: %s', msg);
        end
    end

    if exist(stm32Dst, 'dir')
        [ok, msg] = rmdir(stm32Dst, 's');

        if ~ok
            error('Cannot remove old STM32 Source_Simulink: %s', msg);
        end
    end

    [ok, msg] = copyfile(dstRoot, stm32Dst);

    if ~ok
        error('Cannot copy generated files to STM32: %s', msg);
    end


    %% 9. Verify output files

    stm32MainDir = fullfile(stm32Dst, mainModelName);

    % Check required main model files.
    for i = 1:numel(requiredMainFiles)

        filePath = fullfile( ...
            stm32MainDir, requiredMainFiles{i});

        if ~exist(filePath, 'file')
            error('STM32 output is missing required file: %s', ...
                filePath);
        end
    end

    % Ensure ert_main.c has not been copied into BLDC_MOTOR.
    if exist(fullfile(stm32MainDir, 'ert_main.c'), 'file')
        error('Unexpected ert_main.c found in STM32 output.');
    end

    % Verify the shared utility header.
    if ~exist(fullfile(stm32Dst, 'rtwtypes.h'), 'file')
        error('STM32 output is missing rtwtypes.h.');
    end

    % Warn if the expected Controller SWC is missing.
    if ~exist(fullfile(stm32Dst, 'Controller', 'Controller.c'), 'file')
        warning(['Controller.c not found in STM32 output. ', ...
            'Check the SWC generated file name.']);
    end


    %% 10. Report

    fprintf('\n');
    fprintf('============================================\n');
    fprintf(' Simulink source collection completed\n');
    fprintf('============================================\n');
    fprintf('Main model files : %d\n', mainFileCount);
    fprintf('SWC folders      : %d\n', swcCount);
    fprintf('SWC C/H files    : %d\n', swcFileTotal);
    fprintf('Shared C/H files : %d\n', sharedFileCount);
    fprintf('Project output   : %s\n', dstRoot);
    fprintf('STM32 output     : %s\n', stm32Dst);
    fprintf('Model folder     : %s\n', stm32MainDir);
    fprintf('Excluded file    : ert_main.c\n');
    fprintf('============================================\n\n');

end