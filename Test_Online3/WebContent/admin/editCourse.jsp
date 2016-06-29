<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
  <%@taglib prefix="s" uri="/struts-tags"%>  
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>编辑课程信息</title>

</head>
<body>
    <s:form action="course">
    		<s:hidden name="action" value="editsave"/>
    		<s:hidden name="id" valude="id"/>
    		<s:textarea name="name" label="课程名称" rows="4"  style="border-style: Groove; width:686px;"></s:textarea><br/>
    		<s:textarea name="planNum" label="计划学生数" rows="4"  style="border-style: Groove; width:686px;"></s:textarea><br/>
    	
    	   
    		<s:textarea name="teacher" label="任课教师" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>
    		<s:textarea name="xuefen" label="课程学分" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>
    		<s:textarea name="time" label="上课时间" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>
    		<s:textarea name="classroom" label="教室" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>

    		<s:submit value="保存" ></s:submit>
    		
    		<button onclick="history.back(-1)" class="B1">返回</button>
    </s:form>
</body>
</html>