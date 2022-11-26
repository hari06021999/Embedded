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
            emailext to: "hariharan.m@felicitoussolutions.com",
            subject: "Test Email From Jenkins",
            body: "I Hope all of you getting Email's From Jenkins '\n' BUILD STATUS: ${currentBuild.currentResult}: Job ${env.JOB_NAME}\nMore Info can be found here: ${env.BUILD_URL}",
            attachLog: true
        }
    }
     
   //,shivani.b@felicitoussolutions.com,info@felicitoussolutions.com,musthaba@felicitoussolutions.com,barath_ks@felicitoussolutions.com
       
}
    

