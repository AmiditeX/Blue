pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh '''qmake Blue/Blue.pro
make'''
      }
    }
  }
}