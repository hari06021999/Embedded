pipeline {
    agent any 

    environment {
        TOOL_DIR = "${WORKSPACE}\\ci-cd-tool"
    }

    stages {
        stage('Build') { 
            steps {
                bat "${TOOL_DIR}\\build.bat ${WORKSPACE}\\Debug Debug all"
            }
        }
        
        
//     stage('Flash-Debug') { 
//             steps {
//                 bat "${TOOL_DIR}\\flash.bat $params.DUT_STLINK_sn ${WORKSPACE}\\Debug\\LED.elf"
//             }
//         }  
        
    
       
    }
     post{
        always{
            emailext to: "hariprithi99@gmail.com",
            subject: "Test Email",
            body: "Test",
            attachLog: true
        }
    }
     
   
       
}
    

