pipeline {
  agent any
  stages {
    stage('Build') {
      parallel {
        stage('Build') {
          steps {
            sh '''qmake Blue/Blue.pro
make'''
          }
        }
        stage('') {
          steps {
            sh 'whoami env '
          }
        }
      }
    }
  }
}