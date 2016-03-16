
module t2(input CLOCK_50, output [0:0] LEDG);
  
  reg lamp = 0;
  reg [25:0] cont;
  assign LEDG = lamp;
  
always @(posedge CLOCK_50) begin
       if(cont == 50000000) begin
         lamp <= ~lamp;
         cont <= 0; 
       end else begin
        cont <= cont+1;
       end
   end  
endmodule 	

