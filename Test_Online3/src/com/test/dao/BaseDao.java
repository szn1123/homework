package com.test.dao;


import java.lang.reflect.ParameterizedType;
import java.util.List;

import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

import com.test.util.HibernateUtil;

public abstract class BaseDao <T>{
	 private Session session;  
	 private Transaction tx;  
	 private Class<T> clazz;
	 
 
@SuppressWarnings("unchecked")
protected BaseDao() {  
	        ParameterizedType type = (ParameterizedType)getClass().getGenericSuperclass();
	        clazz = (Class<T>)type.getActualTypeArguments()[0];
	}  
   
	public void insert(T o){
		session = HibernateUtil.getSession();
		tx = session.beginTransaction();
		session.save(o);
		tx.commit();
		session.close();
	}
	
	public void delete(T o){
		 session = HibernateUtil.getSession();
		tx = session.beginTransaction();
		session.delete(o);
		tx.commit();
		session.close();
	}
	public void deleteById(Integer id){
		session = HibernateUtil.getSession();
		tx =session.beginTransaction();
		String hql = "delete "+clazz.getName()+" where id = ?";
		Query query = session.createQuery(hql);
		query.setInteger(0, id);
		query.executeUpdate();
		tx.commit();
		session.close();
		
	}
	public void update(T o){
		 session = HibernateUtil.getSession();
		tx = session.beginTransaction();
		session.update(o);
		tx.commit();
		session.close();
	}
	@SuppressWarnings("unchecked")
	public T getById(Integer id){
		 session = HibernateUtil.getSession();
		T t = (T)session.get(clazz, id);
		session.close();
		return t;		
	}
	
	@SuppressWarnings("unchecked")
	public List<T> get(){
		 session = HibernateUtil.getSession();
		 List <T> list = session.createQuery("from "+ clazz.getName()).list();
		 session.close();
		 return list;
	}
	
	@SuppressWarnings("unchecked")
	public List<T> query(String hql,Object[] params){
		session = HibernateUtil.getSession();
		Query query = session.createQuery(hql);
		for (int i = 0, len = params.length; i < len; i++) {
			query.setParameter(i + "", params[i]);
		}
		return (List<T>) query.list();
		
	}
	public <T> List<T> queryByName(String name) {
	// TODO Auto-generated method stub
	Session s = HibernateUtil.getSession();
	String hql = "from"+clazz.getName()+" where name like ?";
	Query query = s.createQuery(hql);
	query.setString(0, "%"+name+"%");
	List<T> list = query.list();
	s.close();
	return list;
	}
}
