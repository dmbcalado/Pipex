<h1><strong><em>Get Next Line (grade : 112)</em></strong></h1>
<div align="center"><br /><img src="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" alt="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" width="400" height="200" /></div>
<p>In this project, it is intended to create a function that reads a given file and returns the next line, that means in the first iteration, gives the first line of the file, the second iteration the second line and so on. By the <em>rules given* </em>, and accordingly to <em>"the Norm" of 42 school* </em>, this has to be done in less then 5 functions of maximum 25 lines each.</p>
<p>The only allowed external functions were:</p>
<ul>
<li>read( )</li>
<li>malloc( )</li>
<li>free( )</li>
</ul>
<p>By studying the <tt>ssize_t read(int</tt>&nbsp;<em>fildes</em><tt>, void *</tt><em>buf</em><tt>, size_t</tt>&nbsp;<em>nbyte</em><tt>)</tt> we can conclude that upon successful completion, read() returns a positive integer indicating the number of bytes actually read. Otherwise, the functions shall return -1, and once was read x bytes, then the next x bytes shall be readen in the next call for the read( ) function.</p>
<p>We were not allowed to use global variables as it is forbidden by the <em>"the Norm"</em>, however we were allowed to use static variables. Another important thing to mention is that we had to add the option to compile with any&nbsp;<em>nbyte</em> bigger then 1, using the call: -D BUFFER_SIZE=n.</p>
<p>The way i found to get to the solution of this project was by using a static char array (the <b>buffer </b>)that had size BUFFER_SIZE&nbsp; (and if not defined then would be automatically choosen to be BUFFER_SIZE&nbsp;= 40) and store what was read in the file using the read( ) function as <tt>read(fd, buffer, BUFFER_SIZE).</p>
(To be continued ...)
