module pisca(input [0:0] CLOCK_50, input [0:0] KEY,output [0:0] LEGD);
  
  reg lamp = 0;
  reg [25:0] cont;
  
  assign LEGD = lamp;
  
always @(posedge CLOCK_50, KEY) begin
    if(KEY == 1)begin
      cont <= 0;
      lamp <= 0;
     end else begin
       if(cont == 50) begin
         lamp <= ~lamp;
         cont <= 0; 
       end else begin
        cont <= cont+1;
       end
     end
   end  
endmodule 	

module teste;

  reg CLOCK_50;
  reg KEY;
  wire lamp;
  
  always #1 CLOCK_50 <= ~CLOCK_50;
  
  pisca A(CLOCK_50, KEY, lamp);
  

  initial begin
   $dumpvars(0, A);
      #0
      KEY <= 1;
      CLOCK_50 <= 0;
      
      #1
      KEY <= 0;
      
      #5000
      $finish;   
   end
endmodule

