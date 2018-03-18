
// 将父类基础构造器设为private则不可被继承
class Father{
    private Father(){

    }

    static class Inner{
        private Inner(){

        }
    }
}