#!/usr/bin/python3
# -*- coding: utf-8 -*-
from jira import *
from jira.resources import *
from jira.resources import Issue
from jira.resources import IssueLink
import openpyxl
import requests
import base64
import json
import sys
class myJiraUtil(object):
    def __init__(self):
        self.server = ''
        self.basic_auth = ('', '')
        self.jiraClinet = None
        self.projectname = "SOP2"
        self.JIRA_MY_PROJECT = "10801"
        self.__JIRA_MY_PROJECT = "10801"
        self.__LEVEL_I_ID = "10601"
        self.__LEVEL_II_ID = "10602"

    def login(self):
        try:
            self.jiraClinet = JIRA(server=self.server,basic_auth=self.basic_auth)
            if self.jiraClinet != None:
                print("Login OK")
            else:
                print("Login failed")
        except Exception :
            print("Jira init failed!")
        else:
            print("Jira logined in!")
            return self.jiraClinet

    def getProjectList(self):
        print("======Current Projects in JIRA:\n")
        if self.jiraClinet == None:
            return
        projectslist = self.jiraClinet.projects()
        for project in projectslist:
            print("Project id:"+project.id+"/ Project Name:"+project.name)

    def findIssueById(self, issueId):
        if issueId:
            if self.jiraClinet == None:
                self.login()
            return self.jiraClinet.issue(issueId)
        else:
            return 'Please input your issueId'
    def ShowIssueDetail(self,issueid):
        myissues = self.jiraClinet.issue(issueid)
        # 获取jira单子的属性
        # 注意：以下的属性有部分是字符串，但有部分是对象，还可以深入一层获取详细的信息
        print(myissues.id)  # 缺陷ID
        print(myissues.fields.issuetype)  # 类型
        print(myissues.fields.issuetype.avatarId)  # 类型ID
        print(myissues.fields.project)  # 项目
        print(myissues.fields.fixVersions)  # 解决版本
        print(myissues.fields.resolution)  # 解决结果
        print(myissues.fields.resolutiondate)  # 解决时间
        print(myissues.fields.lastViewed)  # 最后查看时间
        print(myissues.fields.created)  # 创建日期
        print(myissues.fields.priority)  # 优先级
        print(myissues.fields.versions)  # 影响版本
        print(myissues.fields.assignee)  # 经办人
        print(myissues.fields.updated)  # 修改日期
        print(myissues.fields.status)  # 状态
        print(myissues.fields.components)  # 所属模块
        print(myissues.fields.description)  # 描述
        print(myissues.fields.attachment)  # 附件信息
        print(myissues.fields.summary)  # 主题
        print(myissues.fields.creator)  # 创建人
        print(myissues.fields.reporter)  # 报告人
        print(myissues.fields.comment.comments)  # 评论
        print(myissues.fields.issuelinks)
        #print(myissues.fields.issuelinks.type)

    def CreateAnIssue(self,summary,description,issuetype):  #defalut priority is Medium
        field = {
            "project": {"id": self.JIRA_MY_PROJECT},
            "summary": summary,
            "description": description,
            "issuetype": {'id': issuetype},
            "priority": {'name': "Medium"},
           # "issuelinks"
        }
        return self.jiraClinet.create_issue(fields=field)
    def UpdateIssueLink(self,issuename,targetissue):
        current_issue = self.jiraClinet.issue(issuename)
        fields ={
            "summary":targetissue
        }
        current_issue.update(fields)
        current_fields=current_issue.fields()
    def getIssuelinkType(self):
        for typeIssue in self.jiraClinet.issue_link_types():
            print(typeIssue)
    def createIssuelink(inward,ward):
        self.jiraClinet.create_issue_link( type="Issue split",inwardIssue="SOP2-1822", outwardIssue="SOP2-1820")
    def task_UploadFeaturelist(excelfile):





    def test(self):
        aissue = self.jiraClinet.issue("SOP2-1820")
        bissue = self.jiraClinet.issue("SOP2-1822")
        cissue = self.jiraClinet.issue("SOP2-318")
        dissue = self.jiraClinet.issue("SOP2-319")
        
        print(self.jiraClinet.users())
        
        #new_issue = 'TEST-1000'
        #parent_issue = 'TEST-2000'
        #

 
        #print(issuelinklist)
        #issuelinklist.
        #aissue.update(aaoptions)
        

if __name__ == '__main__':
    pass