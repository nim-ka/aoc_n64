pipeline {
  agent any
  stages {
    stage('Build Tools') {
      steps {
        sh '''cd tools/
make'''
      }
    }
    stage('Build J Source') {
      steps {
        sh 'make VERSION=jp'
      }
    }
    stage('Build U Source') {
      steps {
        sh 'make VERSION=us || :'
      }
    }
  }
  environment {
    QEMU_IRIX = '/data/n64dev/irixsys/qemu-irix'
  }
}