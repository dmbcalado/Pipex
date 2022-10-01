<h1><em>Pipex</em><strong><em> (grade : 125)</em></strong></h1>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" alt="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" width="400" height="200" /></div>
<p><strong>This project has to goal to understand and use forks, pipes and redirections.</strong></p>
<p>In the mandatory part, the task given is to have a program that would perform the same task as in bash of the following command :</p>
<p><strong>&lt; inputfile cmd1 | cmd 2 &gt; outputfile</strong></p>
<p>with the following call:</p>
<p><strong>./pipex inputfile cmd1 cmd 2 outputfile</strong></p>
<p>Where :</p>
<ul>
<li><strong>&nbsp;inputfile&nbsp; -&gt; </strong>the name of the file to take as input.</li>
<li><strong>outputfile -&gt;&nbsp;</strong>the name of the file to take or create as output.</li>
<li><strong>cmd 1&nbsp; &nbsp; &nbsp; &nbsp;-&gt;&nbsp;</strong>the first command to execute, with any flag or argument required.</li>
<li><strong>cmd 2&nbsp; &nbsp; &nbsp; &nbsp;-&gt;</strong> the second command to execute, and again, with any flag or argument required.</li>
</ul>
<p>example :</p>
<p>$&gt; ./pipex inputfile.txt "grep world" wc outputfile.txt</p>
<p>should perform the same as:</p>
<p>$&gt; &lt; inputfile.txt grep world | wc &gt; outputfile.txt</p>
<p>That is, it should take input file descriptor as the input for the command <em>grep world</em>, take the output as the input to the <em>wc</em> command, and send the output to the to the output file descriptor.</p>
<p>But in order to do so, we need to be able to both run the commands, and to modify its inputs and outputs. This is where the <strong>execve()</strong> function comes, as the function that will execute our commands, and <strong>dup2()</strong> function will redirect the input and output of both the process and each file descriptor needed. But this raises a small issue, the exec family functions kill the program. Also, this raises the problem that we cant send the output of one command to another as straight forward as it may sound.</p>
<p>This requires an introduction to two concepts:</p>
<p><strong>Forks and pipes. </strong> Creating the fork is the solution to the execve() function killing the program, since by creating a fork we are creating a new process (the child process), and by so we can kill the child process. The pipe will solve how to transfer information to one command to the other since by using dup2 we can set the fd of input of the first child as the inputfile file descriptor, and the output to the write (1) entrance of the pipe.</p>
<p>On the second child, we set the input as the read (0) entrance of the pipe and the output is the file descriptor of the outputfile.</p>
<p>I've created an ilustration to visualize what was said:</p>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/99777188/193394465-63cd0f63-2658-4f3c-8f55-977a140a93fc.png" width="330" height="660" /></div>
<p>The bonus part of the work was to not also be able to run:</p>
<p><strong>&lt; inputfile cmd1 | (...) cmdN &gt; outputfile</strong></p>
<p>with the following call:</p>
<p><strong>./pipex inputfile cmd1 (...) cmdN outputfile</strong></p>
<p>and if called, to perform the same task as an heredoc, that is take the input of the terminal as the input to the command till the EOF is given or CNTRL D. They specify the usage to only one particular case:</p>
<p><strong>&lt;&lt; key cmd1 | (...) cmdN &gt;&gt; outputfile</strong></p>
<p>with the following call:</p>
<p><strong>./pipex heredoc key cmd1 (...) cmdN outputfile\</strong></p>
<p>So the task now is to perform the same task as an<strong> heredoc</strong> and to<strong> append</strong> the output of the commands ran on the heredoc in the outputfile.</p>
<p>The logic used was quite similar to the one described above, to append was just to change the flag <strong>0_TRUNC to 0_APPEND</strong>, and the heredoc could be both a pipe or a hidden file as a file descriptor.</p>
<p>As my grade i got 125, getting full grade on both mandatory and bonus parts.</p>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/99777188/193395212-77b31dcb-76cb-478f-8024-16e6b4960e28.png" width="600" height="200" /></div>
