pipeline {
    agent any 

    stages {
        stage('Build') { 
            steps {
              bat '''cd source
gcc -o seg.exe seg.c
seg'''
            }
        }
    }
}
