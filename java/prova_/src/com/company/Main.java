package com.company;


class foo
{
    String[] cibi={"mela","carne","carota","limone"};
    private static String name;
    public foo(String name_)//costractor
    {
        name=name_;
    }
    static void sayHello()
    {
        System.out.println("Hello "+name+" nice to meet you");
    }
}
public class Main
{

    public static void main(String[] args)
    {
        foo obj=new foo("Marco");
        for(String i: obj.cibi)
            System.out.println(i);
        obj.sayHello();
    }
}
