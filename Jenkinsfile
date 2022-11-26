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
    stage('Flash-Debug') { 
            steps {
                bat "${TOOL_DIR}\\flash.bat $params.DUT_STLINK_sn ${WORKSPACE}\\Debug\\LED.elf"
            }
        }  
        
     stage ('Email')
        {
            steps{
                emailext (to: 'hariprithi99@gmail.com', replyTo: 'hariprithi99@gmail.com', subject: "Email Report from - '${env.JOB_NAME}' ", body: readFile("target/surefire-reports/emailable-report.html"), mimeType: 'text/html'); 
            }
        }
       
    }
     
   
       
}
    

