pipeline {
  agent any
  stages {
    stage('error') {
      parallel {
        stage('error') {
          steps {
            sh 'sudo add-apt-repository ppa:beineri/opt-qt542-trusty -y'
            sh 'sudo apt-get install -y qt54webkit libwebkit-dev libgstreamer0.10-dev'
          }
        }
        stage('') {
          steps {
            git(url: 'https://github.com/AmiditeX/Blue.git', branch: 'master')
          }
        }
      }
    }
  }
}