package com.test.serviceImpl;
import java.util.List;

import com.test.dao.StudentDao;
import com.test.model.Student;
import com.test.service.StudentService;
public class StudentServiceImpl implements StudentService{

	StudentDao studentDao = new StudentDao();
	@Override
	public Student findById(Integer id) {		
		// TODO Auto-generated method stub
		//System.out.println("username="+studentDao.getById(id).getUserame());
		return studentDao.getById(id);		
	}

	@Override
	public Student findStudentByUsername(String username) {
		// TODO Auto-generated method stub
		System.out.println("service"+username);
		return studentDao.getByUsername(username);
		
	}
	

	@Override
	public void saveStudent(Student student) {
		// TODO Auto-generated method stub
		studentDao.insert(student);
		
		
	}

	@Override
	public void removeStudentById(Integer id) {
		// TODO Auto-generated method stub
		studentDao.deleteById(id);
	}

	@Override
	public List<Student> getList() {
		// TODO Auto-generated method stub
		return studentDao.get();
	}

	@Override
	public void updateStudent(Student student) {
		// TODO Auto-generated method stub
		studentDao.update(student);
		
	}

	@Override
	public List<Student> findStudentByName(String name) {
		// TODO Auto-generated method stub
		return null;
	}

}
