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
        extendedEmail {
                recipientList('xyzcoders@xyz.com')
                defaultSubject("Jenkins Job started : ${jobName}")
                defaultContent("See the latest build in the jenkins job here https://jenkins.xyz.com/job/${jobName}/")
                contentType('text/html')
                triggers {
                    failure {
                        content("See the latest build in the jenkins job here https://jenkins.xyz.com/job/${jobName}/")
                        contentType('text/html')
                        recipientList('xyzcoder@xyz.com')
                        subject("Build Failed in Jenkins: ${jobName}")
                    }
                    success {
                        content('See the latest build in the jenkins job here https://jenkins.xyz.com/job/${jobName}/ <pre> ${BUILD_LOG, maxLines=30, escapeHtml=false} </pre>')
                        contentType('text/html')
                        recipientList('xyzcoder@xyz.com')
                        subject("Build Success in Jenkins: ${jobName}")
                    }
                }
            }
    }
       
}
    

