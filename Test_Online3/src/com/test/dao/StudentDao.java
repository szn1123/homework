package com.test.dao;

import java.util.List;

import org.hibernate.Query;
import org.hibernate.Session;

import com.test.model.Student;
import com.test.util.HibernateUtil;

public class StudentDao extends BaseDao<Student>{

	@SuppressWarnings("unchecked")
	public  Student getByUsername(String username) {
	// TODO Auto-generated method stub
	Session s = HibernateUtil.getSession();
	String hql = "from User where username = '"+username+"'";
	Query query = s.createQuery(hql);
	List<Student> list = query.list();
	s.close();
	return list.get(0);
	}

}
