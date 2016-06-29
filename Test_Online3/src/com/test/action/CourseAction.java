package com.test.action;

import java.util.ArrayList;
import java.util.List;

import com.test.dao.CourseDao;
import com.test.model.Course;
import com.test.service.CourseService;
import com.test.serviceImpl.CourseServiceImpl;

public class CourseAction extends BaseAction{
	private Integer id;
	private String Name;
	private String Teacher;
	private Integer Xuefen;
	private String Time;
	private String Classroom;
	private Integer planNum;
	private Integer lastNum;
	private Integer num;
	public List<Course> courseList = new ArrayList<Course>();
	private CourseService CourseService = new CourseServiceImpl();
	public String addsave(){
		System.out.println("----addsave-----");
		Course course = new Course();
		//course.setId(1);
		course.setName(getName());
		course.setTeacher(getTeacher());
		course.setXuefen(getXuefen());
		course.setTime(getTime());
		course.setClassroom(getClassroom());
		course.setPlanNum(getPlanNum());
		course.setLastNum(getPlanNum());
		course.setNum(0);
		CourseService.saveCourse(course);
		//reset();
		return list();
	}
	public String addcourse(){
		return "addcourse";
	}
	public String list()
	{
		System.out.println("----list----");
		System.out.println("Name="+Name);
		this.setAction("list");
		this.courseList.addAll(this.CourseService.getList());
	
		return "courses";
	}
	public String edit()
	{
		//this.setAction(editsave());
		Course course = this.CourseService.findById(id);
		this.setName(course.getName());
		this.setXuefen(course.getXuefen());
		this.setTime(course.getTime());
		this.setClassroom(course.getClassroom());
		this.setPlanNum(course.getPlanNum());
		this.setLastNum(course.getLastNum());
		this.setTeacher(course.getTeacher());
		this.setNum(getNum());
		return "edit";
	}
	public String editsave()
	{
		Course course = new Course();
		System.out.println("id="+id);
		course.setId(id);
		course.setName(getName());
		course.setTeacher(getTeacher());
		course.setXuefen(getXuefen());
		course.setTime(getTime());
		course.setClassroom(getClassroom());
		course.setNum(this.num);
		course.setPlanNum(getPlanNum());
		course.setLastNum(getPlanNum()-this.num);
		CourseService.updateCourse(course);
		//reset();
		return list();
	}
	public String backmain(){
		return "adminMain";
	}
	
	public String view(){
		this.courseList.addAll(this.CourseService.getList());
		
		return "view";
	}
	
	public String del(){

		CourseService.removeCourseById(id);
		return list();
	}
	public String select()
	{
		this.courseList.addAll(this.CourseService.findCourseByName(getName()));
		return "courses";
	}
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getName() {
		return Name;
	}
	public void setName(String Name) {
		this.Name = Name;
	}
	public String getTeacher() {
		return Teacher;
	}
	public void setTeacher(String Teacher) {
		this.Teacher = Teacher;
	}
	public Integer getXuefen() {
		return Xuefen;
	}
	public void setXuefen(Integer integer) {
		this.Xuefen = integer;
	}
	public String getTime() {
		return Time;
	}
	public void setTime(String Time) {
		this.Time = Time;
	}
	public String getClassroom() {
		return Classroom;
	}
	public void setClassroom(String Classroom) {
		this.Classroom = Classroom;
	}
	public Integer getPlanNum() {
		return planNum;
	}
	public void setPlanNum(Integer planNum) {
		this.planNum = planNum;
	}
	public Integer getLastNum() {
		return lastNum;
	}
	public void setLastNum(Integer lastNum) {
		this.lastNum = lastNum;
	}
	public Integer getNum() {
		return num;
	}
	public void setNum(Integer num) {
		this.num = num;
	}

}
