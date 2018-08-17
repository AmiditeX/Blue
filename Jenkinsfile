pipeline {
  agent none
  stages {
    stage('Qt Installation') {
      steps {
        sh ' sudo add-apt-repository ppa:beineri/opt-qt542-trusty -y'
        sh 'sudo apt-get update -y; true'
        sh 'sudo apt-get install -y qt54webkit libwebkit-dev libgstreamer0.10-dev'
      }
    }
  }
}