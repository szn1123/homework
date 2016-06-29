package com.test.serviceImpl;

import java.util.List;

import com.test.dao.CourseDao;
import com.test.model.Course;
import com.test.service.CourseService;

public class CourseServiceImpl implements CourseService{
    CourseDao courseDao = new CourseDao();
	@Override
	public Course findById(Integer id) {
		// TODO Auto-generated method stub
		return courseDao.getById(id);
	}

	@Override
	public List<Course> findCourseByName(String name) {
		// TODO Auto-generated method stub
		return courseDao.queryByName(name);
	}

	@Override
	public void saveCourse(Course course) {
		// TODO Auto-generated method stub
		courseDao.insert(course);
		
	}

	@Override
	public void removeCourseById(Integer id) {
		// TODO Auto-generated method stub
		courseDao.deleteById(id);
		
	}

	@Override
	public List<Course> getList() {
		// TODO Auto-generated method stub
		return courseDao.get();
	}

	@Override
	public void updateCourse(Course course) {
		// TODO Auto-generated method stub
		courseDao.update(course);
		
	}

}
