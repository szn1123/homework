package com.test.dao;

import java.util.Iterator;
import java.util.List;

import org.hibernate.Session;
import org.hibernate.Transaction;

import com.test.model.User;
import com.test.util.HibernateUtil;

public class UserDao extends BaseDao<User>{
	 private Session session;  
	 private Transaction tx;  
	 public boolean check(User user) {  
		    session = HibernateUtil.getSession();
	        tx = session.beginTransaction();  
	        String hql = "from User u where u.username='" +user.getUsername()+"'";  
	        List list = session.createQuery(hql).list();  
	        if(!list.isEmpty()) {  
	            Iterator it = list.iterator();  
	            while(it.hasNext()) {  
	                String get =  ((User) it.next()).getPassword();  
	                System.out.println(get);  
	                if(get.equals(user.getPassword())) {  
	                    session.close();
	                    return true;  
	                }  
	            }  
	        }  
	        session.close();  
	        return false;     
	    }  
}
