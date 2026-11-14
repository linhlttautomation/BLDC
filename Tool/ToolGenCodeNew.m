
function ToolGenCodeNew()

    clc;

    projectDir = 'D:\BLDC';
    Model = 'BLDC_MOTOR_ASW';

    mainModelSrc = 'D:\BLDC_MOTOR_ASW_ert_rtw';

    slprjDir = 'D:\slprj';
    ertDir = fullfile(slprjDir, 'ert');

    addpath(genpath(projectDir));

    if ~bdIsLoaded(Model)
        load_system(Model);
    end

    %% 1. Clean Simulink build

    fprintf('\n========== CLEAN ==========\n');

    slbuild(Model, 'CleanTopModel');

    %% 2. Remove old generated directories

    if exist(ertDir, 'dir')
        rmdir(ertDir, 's');
        fprintf('[CLEAN] Removed ERT directory\n');
    end

    if exist(mainModelSrc, 'dir')
        rmdir(mainModelSrc, 's');
        fprintf('[CLEAN] Removed model generated directory\n');
    end

    %% 3. Rebuild

    fprintf('\n========== BUILD ==========\n');

    slbuild(Model, 'ForceTopModelBuild', true);

    %% 4. Report

    coder.report.generate(Model);

    %% 5. Close model

    close_system(Model, 0);

    %% 6. Collect files

    MoveFileToSource(projectDir);

    fprintf('\n========== DONE ==========\n');

end
