pipeline {
    agent any 

    environment {
        TOOL_DIR = "${WORKSPACE}\\ci-cd-tool"
    }

   
        stage('Build') { 
            steps {
                bat "${TOOL_DIR}\\build.bat ${WORKSPACE}\\Debug Debug all"
                bat "${TOOL_DIR}\\build.bat ${WORKSPACE}\\Release Release all"
            }
        }
    }
}
