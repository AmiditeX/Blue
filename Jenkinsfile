pipeline {
  agent any
  stages {
    stage('Build') {
      agent {
        dockerfile {
          filename 'amiditex/jenkins-dev'
        }

      }
      steps {
        sh '''qmake Blue/Blue.pro
make -j 4'''
      }
    }
    stage('Cpp test') {
      steps {
        sh '''cppcheck --enable=all --inconclusive --xml --xml-version=2 Blue 2> cppcheck.xml
'''
        publishCppcheck(severityError: true, severityInformation: true, severityNoCategory: true, severityPerformance: true, severityPortability: true, severityStyle: true, severityWarning: true, XSize: 500, YSize: 500, displayAllErrors: true, displayErrorSeverity: true, displayNoCategorySeverity: true, displayPerformanceSeverity: true, displayPortabilitySeverity: true, displayStyleSeverity: true, displayWarningSeverity: true, pattern: 'cppcheck.xml')
      }
    }
    stage('Artefacts') {
      steps {
        archiveArtifacts(artifacts: 'release/Blue', caseSensitive: true)
      }
    }
  }
}