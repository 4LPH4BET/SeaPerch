pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                echo "My branch is: ${env.BRANCH_NAME}"
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
    }
    // Define your secret project token here
    def project_token = 'abcdefghijklmnopqrstuvwxyz0123456789ABCDEF'

    // Reference the GitLab connection name from your Jenkins Global configuration (http://JENKINS_URL/configure, GitLab section)
    properties([
        gitLabConnection('SeaPerch'),
        pipelineTriggers([
            [
                $class: 'SeaPerch',
                branchFilterType: 'All',
                triggerOnPush: true,
                triggerOnMergeRequest: false,
                triggerOpenMergeRequestOnPush: "never",
                triggerOnNoteRequest: true,
                noteRegex: "Jenkins please retry a build",
                skipWorkInProgressMergeRequest: true,
                secretToken: project_token,
                ciSkip: false,
                setBuildDescription: true,
                addNoteOnMergeRequest: true,
                addCiMessage: true,
                addVoteOnMergeRequest: true,
                acceptMergeRequestOnSuccess: false,
                branchFilterType: "NameBasedFilter",
                includeBranchesSpec: "release/qat",
                excludeBranchesSpec: "",
            ]
        ])
    ])
}
