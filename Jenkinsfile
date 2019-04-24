pipeline {
  agent none
  stages {
    stage('API Testing') {
	  agent { docker 'node:7' } 
      steps {
			parallel(
				NewmanAPI: {
					slackSend color: "229954", message: "Starting *API Testing* Job"
					
					slackSend color: "cceef9", message: "`Starting API Test Execution` Job Details: ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.BUILD_URL}|Open>)"
					slackSend color: "cceef9", message: "`Creating Node Docker container for Postman / Newman CLI`"					
							
					sh '''
						echo "Starting Newman"
						chmod 777 ./ci/scripts/functional-test.sh
						./ci/scripts/functional-test.sh
					'''
					sh 'sleep 10'
					
					slackSend color: "cceef9", message: "`Archieving test results...`"

					junit 'tests/*.xml'
					
					sh 'echo "Complete"'
					
					slackSend color: "cceef9", message: "`Destroying Docker container`"
					slackSend color: "cceef9", message: "`API Test Execution Complete` Job URL: (<${env.BUILD_URL}|Open>) (<${env.BUILD_URL}${"testReport/"}|TestReports>) "
					
					slackSend color: "229954", message: "```End of automation pipeline```"
					
				},
				Notifications: {
					sh 'echo "Notify"'	
					sh 'sleep 6'
					slackSend color: "78909C", message: "Executing TestCase 1: *Validate Test User*"
					sh 'sleep 2'
					slackSend color: "2196F3", message: "TestCase 1: *PASSED*"
					
					
					slackSend color: "78909C", message: "Executing TestCase 2: *Validate Admin User*"
					sh 'sleep 2'
					slackSend color: "2196F3", message: "TestCase 2: *PASSED*"
					
					
					slackSend color: "78909C", message: "Executing TestCase 3: *Validate Admin Role*"
					sh 'sleep 2'
					slackSend color: "2196F3", message: "TestCase 3: *PASSED*"
					
					
					slackSend color: "78909C", message: "Executing TestCase 4: *Get User Name*"
					sh 'sleep 2'
					slackSend color: "2196F3", message: "TestCase 4: *PASSED*"
					
					
				}
			)
		}	 
    }
  }
}
