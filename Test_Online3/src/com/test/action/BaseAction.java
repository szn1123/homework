package com.test.action;

import java.lang.reflect.Method;

import com.opensymphony.xwork2.ActionSupport;

public class BaseAction extends ActionSupport{
	private String action = "";

	public String getAction() {
		return action;
	}

	public void setAction(String action) {
		this.action = action;
	}
	
	public String execute(){
		try{
			String str=this.executeMethod(this.getAction());
			System.out.println("this.action="+str);
			return str;
		}catch(Exception e){
			e.printStackTrace();
			System.out.println("---eeeeeee-----");
			return INPUT;
		}
	}
	
	private String executeMethod(String method) throws Exception{
		Class[] c = null;
		Method m = this.getClass().getMethod(method, c);
		Object[] o = null;
		String result = (String) m.invoke(this, o);
		return result;
	}
}
