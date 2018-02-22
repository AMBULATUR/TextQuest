# TextQuest
https://www.dropbox.com/sh/uw84i7phq9d6ayp/AADO_kgEQ7n5p4qIYb7TuE5ma?dl=0 - Папку закинуть в корень диска D

###########################################################
Только для первого запуска Загрузка всего репозитория
Делаете форк https://github.com/AMBULATUR/TextQuest.git 
Вместо UserName - Имя своего аккаунта на GitHub
(git clone https://github.com/UserName/TextQuest.git)

cd TextQuest 
remote add upstream https://github.com/AMBULATUR/TextQuest.git
git fetch upstream

#На данном этапе делаете комментарий <TYT>

git push # Изменения отправляются на github в ваш репозиторий, в вашем репозитории жмёте PullRequest и сливаете с моим репозиторием

Ждёте пока я одобрю PullRequest

После одобрения сливаете мою ветку с своей

git checkout master
git pull upstream master
git push origin master