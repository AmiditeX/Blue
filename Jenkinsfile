pipeline {
  agent any
  stages {
    stage('Qt Installation') {
      steps {
        sh '''wget -nc https://download.qt.io/official_releases/qt/5.11/5.11.1/qt-opensource-linux-x64-5.11.1.run
'''
        sh ' chmod +x qt-opensource-linux-x64-5.7.0.run'
        sh './qt-opensource-linux-x64-5.7.0.run'
        sh '''sudo apt-get install -y qt54webkit libwebkit-dev libgstreamer0.10-dev
sudo apt-get install libfontconfig1'''
      }
    }
  }
}