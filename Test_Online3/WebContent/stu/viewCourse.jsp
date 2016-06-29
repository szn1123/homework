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
		<th>课程名称</th>
		<th>课余量</th>
		<th>任课教师</th>
		<th>课程学分</th>
		<th>上课时间</th>
		<th>教室</th>
		</tr>
		
			<s:iterator value="%{courseList}" id="course" status="status">
			<tr <s:if test="#status.odd">class="GridDataRow"</s:if>
			<s:else>class="GridAltRow"</s:else> align="center"
			onmouseover="currentcolor=this.style.backgroundColor;
			this.style.backgroundColor='#eaf9d1';style.cursor='hand';"
			onmouseout="this.style.backgroundColor=currentcolor;">
		        <td>
		        <s:property value="#course.name"/>
		        </td>
		         <td>
		        <s:property value="#course.lastNum"/>
		        </td>
		        <td>
		        <s:property value="#course.teacher"/>
		        </td>
		        <td>
		        <s:property value="#course.xuefen"/>
		        </td>
		        <td>
		        <s:property value="#course.time"/>
		        </td>
		        <td>
		        <s:property value="#course.classroom"/>
		        </td>
		        <td>
		        <a  href="javascript:void(0)" onclick="location.href='course.action?action=select&id=<s:property value="#course.id"/>'">选课</a>
				</td>
			</tr>
			</s:iterator>
		       
	</table>  
	<a   href="javascript:void(0)" onclick="location.href='course.action?action=backmain';">返回</a> <br/>
</body>
</html>