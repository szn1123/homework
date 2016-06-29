package com.test.service;

import java.util.List;

import com.test.model.Course;

public interface CourseService {
	Course findById(Integer id);
	List<Course> findCourseByName(String name);
	void saveCourse(Course Course);
	void removeCourseById(Integer id);
	List<Course> getList();
	void updateCourse(Course Course);
}
