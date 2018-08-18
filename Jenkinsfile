pipeline {
  agent any
  stages {
    stage('Build') {
      parallel {
        stage('Build') {
          steps {
            sh '''qmake Blue/Blue.pro
make -j 4'''
          }
        }
        stage('error') {
          steps {
            sh '''whoami
env'''
          }
        }
      }
    }
  }
}