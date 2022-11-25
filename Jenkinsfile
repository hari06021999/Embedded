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
        success {
           mail bcc: '', body: 'Build Success', cc: 'hariprithi1999@gmail.com,hariprithi1999@gmail.com', from: '', replyTo: '', subject: 'Jenkins Integration Process', to: 'hariprithi99@gmail.com'
        }
        unsuccessful {
            script {
                emailext (
                    to: '${DEFAULT_RECIPIENTS}',
                    subject: "Unsuccessful build ${env.BUILD_ID}",
                    body: "Build ${env.BUILD_ID} has result ${currentBuild.currentResult}"
                )
            }
        }
    }
}
