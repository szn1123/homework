<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@taglib prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>学生列表</title>
</head>
<body>
	<s:form action="question">
	<s:hidden name="action" value="select" ></s:hidden>
    <input type="text" value="" name="title">
    <s:submit value="查询" ></s:submit>
    </s:form>
	<table cellspacing="1" border="0" style="color:#333333;width:100%;">
		<tr class="GridHeader" style="height:25px;">
		<th>学号</th>
		<th>姓名</th>
		<th>专业</th>
		<th>班级</th>
		<th>电话</th>
		</tr>
		
			<s:iterator value="%{stuList}" id="stu" status="status">
			<tr <s:if test="#status.odd">class="GridDataRow"</s:if>
			<s:else>class="GridAltRow"</s:else> align="center"
			onmouseover="currentcolor=this.style.backgroundColor;
			this.style.backgroundColor='#eaf9d1';style.cursor='hand';"
			onmouseout="this.style.backgroundColor=currentcolor;">
		        <td>
		        <s:property value="#stu.username"/>
		        </td>
		        <td>
		        <s:property value="#stu.name"/>
		        </td>
		        <td>
		        <s:property value="#stu.major"/>
		        </td>
		        <td>
		        <s:property value="#stu.classNo"/>
		        </td>
		        <td>
		        <s:property value="#stu.mobile"/>
		        </td>
		        <td>
		        <a  href="javascript:void(0)" onclick="location.href='student.action?action=edit&id=<s:property value="#stu.id"/>'">编辑</a>
				<a  href="javascript:void(0)" onclick="location.href='student.action?action=del&id=<s:property value="#stu.id"/>'">删除</a>
				</td>
			</tr>
			</s:iterator>
		       
	</table>  
	<a href="addStu.jsp">添加题目</a>  
	<a href="main.jsp">返回</a>
</body>
</html>