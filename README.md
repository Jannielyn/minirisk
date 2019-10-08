## Github Setup
##### 安装
install Git from [here](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

##### Create ur SSH key
Follow guide from [here](https://help.github.com/en/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent), then [here](https://help.github.com/en/articles/adding-a-new-ssh-key-to-your-github-account)

##### 克隆
***Open Git Bash,***
***go to your folder***
```
git init
git clone git@github.com:fecpp/minirisk.git
```

##### 以下常规操作：先pull再push
```
git pull
```
***after make changes to files...***
```
git add .
git commit -m "some message"
git push
```

![alt text](https://i.stack.imgur.com/nWYnQ.png)
