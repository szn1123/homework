<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
  <%@taglib prefix="s" uri="/struts-tags"%>  
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>查看个人信息</title>

</head>
<body>
 
    		
    		<s:hidden name="id" valude="id"/>
    		<s:label name="username" label="学号" rows="4"   ></s:label><br/>
    		
    	
    	   
    		<s:label name="name" label="姓名" rows="2" cols="20"  ></s:label><br/>
    		<s:label name="major" label="专业" rows="2" cols="20"  ></s:label><br/>
    		<s:label name="classNo" label="班级" rows="2" cols="20"  ></s:label><br/>
    		<s:label name="mobile" label="电话" rows="2" cols="20"  ></s:label><br/>

    		
    		
    		<button onclick="history.back(-1)" class="B1">返回</button>
 
</body>
</html>