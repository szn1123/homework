<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
  <%@taglib prefix="s" uri="/struts-tags"%>  
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>修改学生信息</title>

</head>
<body>
    <s:form action="student">
    		<s:hidden name="action" value="editsave"/>
    		<s:hidden name="id" valude="id"/>
    		<s:textarea name="username" label="学号" rows="4"  style="border-style: Groove; width:686px;"></s:textarea><br/>
    		
    	
    	   
    		<s:textarea name="name" label="姓名" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>
    		<s:textarea name="major" label="专业" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>
    		<s:textarea name="classNo" label="班级" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>
    		<s:textarea name="mobile" label="电话" rows="2" cols="20" style="border-style: Groove; width:586ps;"></s:textarea><br/>

    		<s:submit value="保存" ></s:submit>
    		
    		<button onclick="history.back(-1)" class="B1">返回</button>
    </s:form>
</body>
</html>