using System;
using System.Collections.Generic;
using System.Text;

namespace CSharpConsole
{
    class GitRepoFileCopy
    {
        const string COPY_PATH = "D:\\Program Files\\Programmers_Algorithm\\CppCsharpRND";
        List<string> list_myDirFile = new List<string>();

        static string GetPath()
        {
            // 실행 파일 기준 3개의 디렉토리 상위에 cs 파일들이 위치함.
            string path = System.IO.Directory.GetCurrentDirectory();
            var path_split = path.Split('\\');
            path = string.Empty;
            for (int i = 0; i < path_split.Length - 3; i++)
            {
                if (i > 0) path += "\\";
                path += path_split[i];
            }

            Console.WriteLine($"현재 디렉토리 : {path}");

            return path;
        }

        static void Main()
        {
            string source_path = GetPath();
            string target_path = COPY_PATH; 
            var all_source_files = System.IO.Directory.GetFiles(source_path);

            foreach (var file in all_source_files)
            {
                string dest_file = string.Format($"{target_path}\\{System.IO.Path.GetFileName(file)}");
                string extension = System.IO.Path.GetExtension(file);
                if(extension == ".cs")
                {
                    System.IO.File.Copy(file, dest_file);
                    Console.WriteLine($"{file}파일이 {COPY_PATH}로 복사되었습니다.");
                }
            }

            
        }
    }

    
}
