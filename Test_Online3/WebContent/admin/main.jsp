<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>管理员菜单</title>
</head>
<body>
	<a   href="javascript:void(0)" onclick="location.href='student.action?action=list';">学生管理</a> <br/>
	<a   href="javascript:void(0)" onclick="location.href='course.action?action=list';">课程管理</a> <br/>
	<a href="javascript:void(0)" onclick="if(confirm('确实要退出系统？')) location.href='login.action?action=loginout';">退出系统</a>
</body>
</html>