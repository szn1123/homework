<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>添加课程</title>
</head>
<body>
	<s:form action="course">
		<s:hidden name="action" value="addsave"/>
		<s:textfield name="name"  label="课程名称"/>
		<s:textfield name="planNum" label="计划学生数量"/>
		<s:textfield name="teacher"  label="任课教师"/>
		<s:textfield name="xuefen"  label="课程学分"/>
		<s:textfield name="time"  label="上课时间"/>
		<s:textfield name="classroom"  label="教室"/>
		<s:submit name="submint" value="确定"/>
		<s:reset name="reset" value="重写"/>
	</s:form>

</body>
</html>