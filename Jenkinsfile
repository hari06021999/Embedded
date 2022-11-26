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
        
         stage ('Email')
        {
            steps{
               emailext body: '${currentBuild.currentResult}: Job ${env.JOB_NAME}\\nMore Info can be found here: ${env.BUILD_URL}', recipientProviders: [requestor(), developers()], subject: 'Email Report from - \'${env.JOB_NAME}', to: 'hariprithi99@gmail.com' 
            }
        }
    stage('Flash-Debug') { 
            steps {
                bat "${TOOL_DIR}\\flash.bat $params.DUT_STLINK_sn ${WORKSPACE}\\Debug\\LED.elf"
            }
        }  
        
    
       
    }
     
   
       
}
    

