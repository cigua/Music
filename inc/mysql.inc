<?php
class mysql{
    //���ӷ����������ݿ��Լ�ִ��SQL�������
    public $database;
    public $server_username;
    public $server_userpassword;
    public $link;
    //public $conn;
    function mysql()
  	{  //���캯����ʼ����Ҫ���ӵ����ݿ�
       $this->server_username="xiaom";
       $this->server_userpassword="xiaom";
       $this->database="voice";
       $this->link=mysqli_connect('localhost',$this->server_username,$this->server_userpassword,$this->database);
       
       }//end mysql()
  function link($database)
  	{  //���ӷ����������ݿ�
       //�����������ӵ����ݿ�
        if ($database==""){
            
            }else{
            $this->database=$database;
            }
        //���ӷ����������ݿ�
     	if(@$id=mysql_connect('localhost',$this->server_username,$this->server_userpassword)){
		     //echo "���ݿ����Ӵ���111������";
          if(!mysql_select_db($this->database,$id)){
		       echo "���ݿ����Ӵ���222������";
               exit;
               }
 	       }else{
               echo "����������ά���У����Ժ����ԣ�����";
               exit;
      	   }
	}//end link($database)
	function excu($query)
    {     //ִ��SQL���
    	$conn=new mysqli('localhost',$this->server_username,$this->server_userpassword,$this->database);
    		if($result=$conn->query($query)){
    			$conn->close();
				return $result;
        	}else{
             	echo "sql���ִ�д��󣡣���������!!!";
       		    exit;
        	}
    } //end  exec($query)
} //end class mysql

	function my_query($sql){
		$conn=new mysqli('localhost',$this->server_username,$this->server_userpassword,$this->database);
		$res_arr=new ArrayObject();
		$result=$mysqli->query($query);
		if ($result) {
			if($result->num_rows>0){                                               //�жϽ�������е���Ŀ�Ƿ����0
				$i=0;
				while($row =$result->fetch_array() ){                        //ѭ�����������еļ�¼
				 	$res_arr->append($row);
				 	//$i++;
				}
			}
		}else {
			echo "��ѯʧ��";
		}
		$result->free();
		$conn->close();
		return $res_arr;
	}
?>