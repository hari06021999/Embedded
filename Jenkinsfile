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
            emailext to: "hariharan.m@felicitoussolutions.com,shivani.b@felicitoussolutions.com,info@felicitoussolutions.com,musthaba@felicitoussolutions.com,barath_ks@felicitoussolutions.com",
            subject: "Test Email From Jenkins",
            body: "I Hope all of you getting Email's from Jenkins ",
            attachLog: true
        }
    }
     
   
       
}
    

