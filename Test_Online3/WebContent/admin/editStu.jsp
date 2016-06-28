<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>修改学生</title>
</head>
<body>
	<s:form action="student">
	<s:hidden name="action" value="editsave"/>
	<s:hidden name="id" value="id"/>
		<s:textfield name="username"  label="学号"/>
		<s:textfield name="name"  label="姓名"/>
		<s:textfield name="major"  label="专业"/>
		<s:textfield name="classNo"  label="班级"/>
		<s:textfield name="mobile"  label="手机"/>
		<s:submit name="submint" value="确定"/>
		<s:reset name="reset" value="重写"/>
	</s:form>

</body>
</html>