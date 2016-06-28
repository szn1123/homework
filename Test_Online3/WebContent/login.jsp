<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>在线考试系统</title>
</head>
<body>
	在线考试系统
	<form action="login.action"  method="post">   
	<input type="hidden" name="action" value="login"/>   
		<table cellspacing="3" cellpadding="0" width="100%" border="0" style="line-height:25px;height:100px">
		<tr><td align="right"></td><td></td></tr>
		<tr>
			<td align="right" height="25"><b>用户名：</b></td>  
			<td height="25" align="left"> &nbsp;
			<input type="text" name="username" style="width:250px; height:20px;"/>
			</td>
		</tr>    
		<tr>
			<td align="right" height="25"><b>密  码：</b></td>  
			<td height="25" align="left"> &nbsp;
			<input type="text" name="password" style="width:250px; height:20px;"/>
			</td>
		</tr>    
		<tr>
			<td align="center" colspan="2">
			<input type="submit" class="B1" value="登录"/>
			&nbsp;&nbsp;&nbsp;
			<input type="reset" class="B1" value="重新填写"/>
			</td>
		</tr>
		</table>
	</form>  
	 <s:property value="Greeting"/>   
</body>
</html>