pipeline {
    agent any 

    stages {
        stage('Build') { 
            steps {
               bat '''gcc -o seg.exe seg.c
seg'''
            }
        }
    }
}
