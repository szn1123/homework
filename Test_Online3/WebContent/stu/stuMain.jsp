<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>学生主页</title>
</head>
<body>
	<a href="javascript:void(0)" onclick="location.href='student.action?action=stuEdit'">查看个人信息</a><br/>
	<a href="javascript:void(0)" onclick="location.href='student.action?action=stuEdit'">修改密码</a><br/>
	<a href="javascript:void(0)" onclick="location.href='course.action?action=view'">选课</a><br/>
		<a href="javascript:void(0)" onclick="if(confirm('确实要退出系统？')) location.href='login.action?action=loginout';">退出系统</a>
</body>
</html>