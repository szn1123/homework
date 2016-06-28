package com.test.action;

import java.util.Date;









import com.opensymphony.xwork2.ActionContext;
import com.test.dao.UserDao;
import com.test.model.User;

public class LoginAction extends BaseAction{

	private String username;
	private String password;
	private String Greeting;
	private String type;
	 User user = new User(); 
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}

	public String login(){
		System.out.println(username+" "+password);
		 
	        user.setUsername(getUsername());  
	        user.setPassword(getPassword());
		if("admin".equals(getUsername())&&"123".equals(getPassword())){
				return "adminMain";
		}
		else{
	     	 UserDao userDao = new UserDao();  
		        if(userDao.check(user)) { 
		        	ActionContext context = ActionContext.getContext();
		        	//Date loginTime = Util.formatDateTime(new Date());
		        	//context.getSession().put("loginTime",loginTime);
		        	context.getSession().put("User",getUsername());
		        	
		            return "stuMain";  
		        }  
		        else
		        {
		        	setGreeting("学号或密码错误，请重新输入！");
		        	return "login"; 
		        }
		}
	}
	  public String loginout(){
	    	//ActionContext context = ActionContext.getContext();
	    	//context.getSession().remove(arg0));
	    	System.out.println("---exit---");
	    	return "logout";
	    }
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getGreeting() {
		return Greeting;
	}
	public void setGreeting(String greeting) {
		Greeting = greeting;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	
}
