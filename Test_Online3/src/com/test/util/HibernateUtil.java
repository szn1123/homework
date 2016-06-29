package com.test.util;

import org.hibernate.HibernateException;  
import org.hibernate.Session;  
import org.hibernate.SessionFactory;  
import org.hibernate.Transaction;  
import org.hibernate.cfg.AnnotationConfiguration;
import org.hibernate.cfg.Configuration;  
  
public class HibernateUtil {  
    private static SessionFactory sessionFactory;  
   public static final ThreadLocal<Session> session = new ThreadLocal<Session>();  
      
    static {      
        try {  
            sessionFactory =  new AnnotationConfiguration().configure().buildSessionFactory();  
        } catch (Throwable ex) {  
            throw new ExceptionInInitializerError(ex);  
        }  
    }  
      
    /*  
     * 获得当前session  
     */
    public static Session getSession() throws HibernateException {  
        Session s = (Session) session.get();  
        if(s ==null || !s.isOpen()){  
            s = sessionFactory.openSession();  
            session.set(s);  
        }  
        return s;     
    }  
      
    /*  
     * 回滚  
     */
    public static void rollback(Transaction tx) {  
        try {  
            if(tx != null) {  
                tx.rollback();  
            }  
        } catch (HibernateException e) {  
            System.out.println("rollback faild." + e);  
        }  
    }  
      
    /*  
     * 关闭session  
     */
    public static void closeSession() throws HibernateException {  
        Session s = session.get();  
        session.set(null);  
        if(s != null) {  
            s.close();  
        }  
    }  /*
    private HibernateUtil(){
    	
    }
    /*
    private static final Configuration configuration = new Configuration().configure("/hibernate.cfg.xml");
    private static final SessionFactory sessionFactory = configuration.buildSessionFactory();
    public static Session getSession(){
    	return sessionFactory.openSession();
    }
    public static SessionFactory getSessionFactory(){
    	return sessionFactory;
    }*/
      
}  
