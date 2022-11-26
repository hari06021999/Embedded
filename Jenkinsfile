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
       
    }
     
    post {
            always{
                archiveArtifacts artifacts: '*.txt', onlyIfSuccessful: true
                
                emailext to: "hariprithi99@gmail.com",
                subject: "jenkins build:${currentBuild.currentResult}: ${env.JOB_NAME}",
                body: "${currentBuild.currentResult}: Job ${env.JOB_NAME}\nMore Info can be found here: ${env.BUILD_URL}",
                attachmentsPattern: '*.txt'
                
            cleanWs()
            }
        }
       
}
    

