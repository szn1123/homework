package com.test.action;

import java.util.ArrayList;
import java.util.List;

import com.opensymphony.xwork2.ActionContext;
import com.test.model.Course;
import com.test.model.Student;
import com.test.service.StudentService;
import com.test.serviceImpl.StudentServiceImpl;


public class StudentAction extends BaseAction{
	public List<Student> stuList = new ArrayList<Student>();
	private StudentService StudentService = new StudentServiceImpl();
	private Integer id;
	private String type;
	private String name;
	private String major;
	private String ClassNo;
	private String Mobile;
	private String username;
	private String password;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getMobile() {
		return Mobile;
	}
	public void setMobile(String Mobile) {
		this.Mobile = Mobile;
	}
	public String getMajor() {
		return major;
	}
	public void setMajor(String major) {
		this.major = major;
	}
	public String getClassNo() {
		return ClassNo;
	}
	public void setClassNo(String ClassNo) {
		this.ClassNo = ClassNo;
	}
	
	public String add(){
		Student stu = new Student();
		stu.setName(getName());
		stu.setType("student");
		stu.setUsername(getUsername());
		stu.setMajor(getMajor());
		stu.setMobile(getMobile());
		stu.setClassNo(getClassNo());
		stu.setPassword("123");
		System.out.println("add");
		StudentService.saveStudent(stu);
		return list();
	}
	public String addstu(){
		return "addstu";
	}
	public String list()
	{
		this.stuList.addAll(this.StudentService.getList());
		return "stu";
	}
	
	public String edit()
	{
		//this.setAction(editsave());
		Student stu = this.StudentService.findById(id);
		this.setUsername(stu.getUsername());
		this.setName(stu.getName());
		this.setMajor(stu.getMajor());
		this.setClassNo(stu.getClassNo());
		this.setMobile(stu.getMobile());
		
		
		return "edit";
	}
	public String stuEdit()
	{
		//this.setAction(editsave());
		username=ActionContext.getContext().getSession().get("User").toString();
		System.out.println("uesrname="+username);
		Student stu = this.StudentService.findStudentByUsername(username);
		this.setId(stu.getId());
		this.setUsername(stu.getUsername());
		this.setName(stu.getName());
		this.setMajor(stu.getMajor());
		this.setClassNo(stu.getClassNo());
		this.setMobile(stu.getMobile());
		this.setPassword(stu.getPassword());
		//this.setType(stu.getType());
		
		return INPUT;
	}
	public String editsave()
	{
		System.out.println("----editsave----");
		Student stu = new Student();
		System.out.println("id="+id);
		stu.setId(id);
		stu.setUsername(getUsername());
		stu.setType("student");
		stu.setName(getName());
		stu.setMajor(getMajor());
		stu.setClassNo(getClassNo());
		stu.setMobile(getMobile());
		
		StudentService.updateStudent(stu);
		//reset();
		return list();
	}
	public String stuSave()
	{
		Student stu = new Student();
		System.out.println("studenteditsaveid="+id);
		stu.setId(id);
		stu.setPassword(getPassword());
		stu.setUsername(getUsername());
		stu.setType("student");
		stu.setName(getName());
		stu.setMajor(getMajor());
		stu.setClassNo(getClassNo());
		stu.setMobile(getMobile());
		
		StudentService.updateStudent(stu);
		//reset();
		return SUCCESS;
	}
	public String del(){
		/*Student stu = new Student();
		System.out.println("id="+id);
		stu.setId(id);
		stu.setUsername(getUsername());
		stu.setType(getType());
		stu.setName(getName());
		stu.setMajor(getMajor());
		stu.setClassNo(getClassNo());
		stu.setMobile(getMobile());*/
		
		StudentService.removeStudentById(id);
		return list();
	}
	public String select()
	{
		//this.stuList.addAll(this.StudentService.findStudentByUsername(getName()));

		return "stu";
	}
	public String backmain(){
		return "adminMain";
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
}

