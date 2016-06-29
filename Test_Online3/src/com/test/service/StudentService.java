package com.test.service;

import java.util.List;

import com.test.model.Student;

public interface StudentService {
	Student findById(Integer id);
	List<Student> findStudentByName(String name);
	void saveStudent(Student student);
	void removeStudentById(Integer id);
	List<Student> getList();
	void updateStudent(Student student);
	Student findStudentByUsername(String username);
}
