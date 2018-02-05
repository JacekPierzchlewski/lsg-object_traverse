%
% object_traverse.m
%
% This script measures time in which Octave changes a property of
% a set of objects. Objects are stored in a cell vector.
%
% `Cosniwa` software is used to measure the time.
%
%  Read more on www.speedupcode.com
%
%

function object_traverse()
%
% 'object_traverse'
%
% Main function of the script.
%

    % Vector with the number of objects to be traversed in every test
    vN = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000];

    % Initalise Cosniwa
    cCosniwa('init');

    % Loop over all the tests
    [nTests, ~] = size(vN(:));
    for i=1:nTests
        iN = vN(i);
        time_objects(iN);
    end

    % Print the results
    cCosniwa('resultc');
end


function time_objects(iN)
%
% time_objects:
%
% Function generates the requested number of objects and measures time of
% changing a property in all the objects.
%
% Parameters:
%
%      iN:  [integer number]  The number of objects which will be generated
%                             and traversed.
%

    % Register traverse through objects
    strRegoTr = sprintf(' %d  objects', iN);
    iRegoTr = cCosniwa('reg_code', strRegoTr);

    % Generate the required number of objects
    vC = generate_objects(iN);

    % Traverse through all the objects
    cCosniwa('call_start', iRegoTr);
    traverse_objects(vC, iN);
    cCosniwa('call_stop', iRegoTr);

end

function vC = generate_objects(iN)
%
% 'generate_objects':
%
% Generate the requested number of objects and store them in a cell vector.
%
% Parameters:
%
%     iN:  [integer number]   Size of the cell vector with objects
%
% Return:
%
%     vC:  [cell vector]      Vector with the generated objects
%

    % Start a cell vector with objects
    vC = {};

    % Generate all the needed objects
    for j=1:iN
        vC{j} = sc(j);
    end
end

function traverse_objects(vC, iN)
%
% 'traverse_objects':
%
% Function traverse through all the objects in cell vector `vC` and increases
% property `val` of every object.
%
% Parameters:
%
%     vC:  [cell vector]      Cell vector with all the objects to traverse
%     iN:  [integer number]   Size of the cell vector with objects
%

    % Loop over all the objects
    for j=1:iN
        vC{j}.val++;
    end
end

