function ToolGenCode()

    addpath(genpath('D:\BLDC'));
   
    Model = 'BLDC_MOTOR_ASW';
    
    if(~bdIsLoaded(Model))
        load_system(Model);
    end
    
    slbuild(Model);
    coder.report.generate(Model);

    close_system(Model);
    
    MoveFileToSource('D:\BLDC');

end

